"""
Jesse@FDU-VTS-MIA
created by 2019/12/17
"""
class LinkNode:
    def __init__(self, key=0, val=0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:
    def _delete_node(self, node: LinkNode):
        # 删除一个节点
        pre = node.prev
        nex = node.next
        pre.next = nex
        nex.prev = pre

    def _add_node(self, node: LinkNode):
        # 在头部加入新节点
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def _move_to_head(self, node: LinkNode):
        # 先删除
        self._delete_node(node)
        # 再插入
        self._add_node(node)

    def _pop_tail(self):
        # pop最后一个节点,方便哈希表更新
        node = self.tail.prev
        self._delete_node(node)
        return node

    def __init__(self, capacity: int):
        self.hash = {}
        self.size = 0
        self.capacity = capacity
        self.head, self.tail = LinkNode(), LinkNode()
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        # 查找key,如果不存则返回-1,否则返回相应的值,并更新双向链表
        node = self.hash.get(key, None)
        if not node:
            return -1
        self._move_to_head(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        node = self.hash.get(key, None)
        if not node:  # 不存在,则新建并且插入
            newNode = LinkNode(key, value)
            self.hash[key] = newNode
            self._add_node(newNode)  # 插入新节点
            self.size += 1           # 双向链表的大小加一
            if self.size > self.capacity:  # 如果超过容量,删除尾部
                to_remove = self._pop_tail()
                self.hash.pop(to_remove.key)
                self.size -= 1
        else:  # 存在则更新
            to_update = self.hash[key]
            to_update.val = value
            self._move_to_head(to_update)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
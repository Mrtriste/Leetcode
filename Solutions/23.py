# -*- coding: utf-8 -*-


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def main():
    lists = []
    from queue import PriorityQueue

    que = PriorityQueue()
    for i in range(len(lists)):
        if lists[i]:
            que.put((lists[i].val, i))

    head = cur = ListNode(0)
    while not que.empty():
        v, idx = que.get()
        node = lists[idx]
        cur.next = node
        cur = cur.next
        if node.next:
            lists[idx] = lists[idx].next
            que.put((node.next.val, idx))
    return head.next



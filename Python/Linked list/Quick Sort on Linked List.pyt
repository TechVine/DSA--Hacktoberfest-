def quickSort(head):
    if head is None:
        return None
    h, t = mysort(head)
    t.next = None
    return h

def mysort(head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    if head is None:
        return None, None

    if head and head.next is None:
        return head, head

    left = None
    pleft = None
    right = None
    pright = None

    phead = head
    p = head.next
    while p:
        if p.data < head.data:
            if left is None:
                left = p
                pleft = p
                p = p.next
                pleft.next = None
            else:
                pleft.next = p
                pleft = p
                p = p.next
                pleft.next = None
        elif p.data > head.data:
            if right is None:
                right = p
                pright = p
                p = p.next
                pright.next = None
            else:
                pright.next = p
                pright = p
                p = p.next
                pright.next = None
        elif p.data == head.data:
            phead.next = p
            phead = p
            p = p.next
            phead.next = None

    lhead, ltail = mysort(left)
    rhead, rtail = mysort(right)

    if lhead is None and rhead is None:
        return head, phead
    if lhead is None and rhead is not None:
        phead.next = rhead
        return head, rtail
    elif lhead and rhead is None:
        ltail.next = head
        return lhead, phead
    elif lhead and rhead:
        ltail.next = head
        phead.next = rhead
        return lhead, rtail

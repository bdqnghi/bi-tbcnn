class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Codec( object ):
    def deserialize( self, l ):
        dummy = p = ListNode( '#' )
        for i in l:
            p.next = ListNode( i )
            p = p.next
        return dummy.next

    def serialize( self, p ):
        l = []
        while p:
            l.append( p.val )
            p = p.next
        return l

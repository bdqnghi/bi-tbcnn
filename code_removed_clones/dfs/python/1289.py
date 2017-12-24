#!/usr/bin/python	

def pro(): INDENT
        nodes=int(raw_input())
        edges=int(raw_input())
        visited=[]
        ar=[]
        #create an empty array
        for i in range(nodes): INDENT
                visited.append(0)
                ar.append([])
                for j in range(nodes): INDENT
                        ar[i].append(0)

DEDENT DEDENT         for i in range(edges): INDENT
                t1=int(raw_input())
                t2=int(raw_input())
                ar[t1-1][t2-1]=1
DEDENT         print ar
        stack=[]
        #a stack with operations append() and pop()
        cur=0
        stack.append(cur)
        #print cur
        neib=0
        while len(stack): INDENT
                neib=0
                for i in range(nodes): INDENT
                        if ar[i]: INDENT
                                if not visited[i]: INDENT
                                        neib=1
                                        break
DEDENT                                 else: INDENT
                                        continue
DEDENT DEDENT DEDENT                 if neib: INDENT
                        cur=i
                        stack.append(cur)
                        print cur+1
                        visited[cur]=1
DEDENT                 else: INDENT
                        cur=stack.pop()


DEDENT DEDENT DEDENT if __name__=='__main__': INDENT
        pro()
DEDENT 

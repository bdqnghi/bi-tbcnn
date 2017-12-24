##fantasy football knapsack

##implementing knapsack problem
##method taken from MIT lecture 
##w= weight, v= value i = number aW= available weight
##returns int
def max_val(w, v, i, aW):
    m = {}
    return fast_max_val(w, v, i, aW, m)
    
def fast_max_val(w, v, i,aW, m):
    global num_calls
    num_calls +=1
    try:return m[(i, aW)]
    except KeyError:
        if i == 0:
            if w[i] <= aW:
                m[(i, aW)] = v[i]
                return v[i]
            else:
                m[(i, aW)] = 0
                return 0
        without_i = fast_max_val(w, v, i-1, aW, m)
        if w[i] > aW:
            m[(i, aW)] = without_i
            return without_i
        else:
            with_i = v[i] + fast_max_val(w, v, i-1,aW-w[i] , m)
        res = max(with_i, without_i)
        m[(i, aW)] = res
        return res

##max_weight = 40
##items = [(9.6, 176), (6.7, 167), (10, 166), (8.9, 145), (9, 141), (9.8, 135), (7.8, 131), (6.1, 131), (5.5, 129), (7.5, 126), (6.8, 121), (7.8, 120), (7.7, 118), (8.5, 117), (8.8, 115)]
##w = [9.6, 6.7, 10, 8.9, 9, 9.8, 7.8, 6.1, 5.5, 7.5, 6.8, 7.8, 7.7, 8.5, 8.8]
##v = [176, 167, 166, 145, 141, 135, 131, 131, 129, 126, 121, 120, 118, 117, 115]
##num_calls = 0
##res = max_val(w, v, len(v)-1, max_weight)
####print 'fast max val =', res





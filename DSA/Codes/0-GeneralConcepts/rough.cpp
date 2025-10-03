for i = 1 to n-1:
    ℓ = i + 1;  r = n
    while ℓ ≤ r:
        m = ⌊(ℓ + r)/2⌋
        if A[m] + A[i] == 0: return yes
        if A[i] + A[m] < 0:
            l = m + 1      # need a larger A[m]
        else:
            r = m - 1      # need a smaller A[m]
return no
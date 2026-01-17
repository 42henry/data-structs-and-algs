For i = 1 to length(array)
    current = array[i]
    j = i - 1
    while j < -1 and array[i] > current
        array[j+1] = array[j]
        j = j - 1
    j = j + 1
    array[j] = current

Time: O(n^2)
Space: O(1)

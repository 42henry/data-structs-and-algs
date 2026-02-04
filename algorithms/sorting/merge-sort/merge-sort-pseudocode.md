##Standard merge sort:

func merge_sort(array)

	if length of array == 1
	    return

	for i = 0 to length of array
	    if i < length of array / 2
		    append array[i] to array_1
		else
		    append array[i] to array_2

	merge_sort(array_1)
	merge_sort(array_2)

	count = 0
	array_1_index = 0
	array_2_index = 0
	while count < length of array
	    if array_1[array_1_index] < array_2[array_2_index]
		    array[count] = array_1[array_1_index]
			array_1_index += 1
		else
		    array[count] = array_2[array_2_count]
			array_2_index += 1
		count += 1

	return

##Mostly in place merge sort:

func merge_sort(array, start, end)

	if length of array == 1
	    return

	s1 = start
	e1 = end / 2
	s2 = e1 + 1
	e2 = end

	merge_sort(array, s1, e1)
	merge_sort(array, s2, e2)

	count = start
	temp_array[end + 1]

	while count < end + 1
		if s1 > e1 or array[s1] > array[s2]
		    temp_array[count] = array[s2]
			s2 += 1
		else
		    temp_array[count] = array[s1]
			s1 += 1
		count += 1
	
	for i = start to end
	    array[i] = temp_array[i]

	return

##In place merge sort:

func merge_sort(array, start, end)

	if length of array == 1
	    return

	s1 = start
	e1 = end / 2
	s2 = e1 + 1
	e2 = end

	merge_sort(array, s1, e1)
	merge_sort(array, s2, e2)

	count = start
	gap = s2 - s1
	do //while gap != 1
	    while s1 + gap <= length of array
		    if array[s1 + gap] < array[s1]
			    swap them
			s1 += 1
		gap = gap / 2
		if gap % 2 != 0
		    gap += 1
		s1 = start
	while gap != 1

	return

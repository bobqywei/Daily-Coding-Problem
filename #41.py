def flight_itinerary(flights, start):
	connections = {}

	for connection in flights:
		strt, dest = connection

		if not strt in connections:
			connections[strt] = []

		connections[strt].append(dest)

	def find_path(curr, taken, itinerary):
		itinerary.append(curr)

		if len(taken) == len(flights):
			return itinerary

		if not curr in connections.keys():
			return None

		for dest in connections[curr]:
			if not (curr, dest) in taken:
				temp = taken.copy()
				temp.add((curr, dest))

				ret = find_path(dest, temp, itinerary)
				if ret is not None:
					return ret

		return None

	return find_path(start, set(), [])





n = int(input("Number of (origin, destination) pairs: "))
flights = []

for i in range(n):
	pair = input().split(' ')
	flights.append(pair)

origin = input("Origin: ")

itinerary = flight_itinerary(flights, origin)

if itinerary is None:
	print("No itinerary possible.")
else:
	output = "Itinerary: "
	for i in range(len(itinerary)):
		if i == len(itinerary) - 1:
			output = output + itinerary[i]
		else:
			output = output + itinerary[i] + " -> "
	
	print(output)

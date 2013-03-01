lines = [line.strip() for line in open('beautiful_stringstxt.txt')]

m = lines[0]

out = ''

 

for x in xrange(1, int(m)+1):

	l = lines[x].lower()

	dic = {}

	line = ''

	for i in l:

		if i not in dic:

			line+=i

			if ord(i.lower()) >= ord('a') and ord(i.lower()) <= ord('z'):

				dic[i] = 1

	line = ''.join([char for char in l if char in "abcdefghijklmnopqrstuvwxyz"])

	d = {}

	for lt in line:

		lt.lower()

		lcount = l.count(lt)

		d.update({lt : lcount})

	sum = 0

	dec = 26

	for w in sorted(d, key=d.get, reverse=True):

		rp = int(d[w])

		for j in xrange(0, rp):

			sum += dec

		dec -= 1

	out += 'Case #%d : %d\n' % (x, sum)


with open ('output', 'w') as f: f.write (out)
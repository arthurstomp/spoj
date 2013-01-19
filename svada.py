import sys

class Monkey:

	def __init__(self, f,p):
		self.findspot=f # Achar local (Macacos A)/ Achar ferramentas( Macaco B)
		self.pickcoco=p # Pegar coco (Macacos A)/ Abrir coco (Macacos B)

	# number of coconuts picked
	def numbercocopick(self,seconds):
		if seconds-self.findspot>0:
			return 1 + (seconds-self.findspot	)/self.pickcoco
		elif seconds==self.findspot:
			return 1
		else:
			return 0

def binarysearch(lowsec,upsec,totalsec,vetmonkA,vetmonkB):
	sumcocoA,sumcocoB=0,0
	for a in vetmonkA:
		sumcocoA+=a.numbercocopick((lowsec+upsec)/2)
	#print sumcocoA		
	for b in vetmonkB:
		sumcocoB+=b.numbercocopick(totalsec-(lowsec+upsec)/2)
	#print sumcocoB
	if sumcocoA==sumcocoB or (sumcocoB>sumcocoA and lowsec==(lowsec+upsec)/2):
		return (lowsec+upsec)/2
	elif sumcocoA>sumcocoB:
		return binarysearch(lowsec,(lowsec+upsec)/2,seconds,monkeysA,monkeysB)
	else	:
		return binarysearch((lowsec+upsec)/2,upsec,seconds,monkeysA,monkeysB)

seconds = input()
numbermonkeysA = input()
monkeysA = []

for i in range(numbermonkeysA):
	aux = raw_input().split(" ")
	mA= Monkey(int(aux[0]),int(aux[1]))
	monkeysA.append(mA)

numbermonkeysB = input()
monkeysB = []

for i in range(numbermonkeysB):
	aux = raw_input().split(" ")
	mB= Monkey(int(aux[0]),int(aux[1]))
	monkeysB.append(mB)

result = binarysearch(0,seconds,seconds,monkeysA,monkeysB)
sys.stdout.write(str(result))
	




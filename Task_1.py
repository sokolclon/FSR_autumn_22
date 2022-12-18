from math import sqrt, log, prod 
from random import randint, choice 

prime_list = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127] 

class Number: 
	def __init__(self): 
		self.num: int = 0 
		self.factor: dict[int,int] = {} 
		self.q: list[int] = [] 
	
	def log(self, p:int): 
		return int(log(self.num, p)) 

	def gen(self): 
		while True:
			regen = False
			fact = {2: randint(1, 123)} 
			while True:
				p = choice(prime_list) 
				fact[p] = randint(1, 6) 
				L = Number().set(fact).log(2) 
				if L > 128:
					regen = True
					#print("too big")
					break
				if L > 123 :
					break
			if regen:
				continue
			break
		#print("gened")
		return self.set(fact)

	def set(self, factor: dict[int,int]):
		self.num: int = prod(p**alpha for p, alpha in factor.items()) + 1 
		self.factor: dict[int,int] = factor
		self.q: list[int] = list(factor.keys())
		return self

def lucas_test(n: Number):
	for a in range(2, int(sqrt(n.num))):
		if pow(a, n.num-1, n.num) != 1:
			return 0
		for q in n.q:
			if pow(a, (n.num-1)//q, n.num) != 1:
				if q == n.q[-1]:
					return 1
				continue
			break
	return -1

def start_generation():
	while True:
		n = Number().gen()
		if lucas_test(n) == 1:
			print(n.num)
			print(n.factor)
			break

start_generation()
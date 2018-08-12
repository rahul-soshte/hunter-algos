
def createvocab(corpus):
	word_list=[]
	for i in range(0,len(corpus)):
		word_list=word_list+corpus[i].split()
	# print(word_list)

	unique_words = set(word_list)
	return unique_words

def create_doc_vector(corpus,vocabulary):
	top_level_vector_list=[]
	single_vector_list=[]

	for i in range(0,len(corpus)):
		for m  in vocabulary:
			if m in corpus[i]:	
				single_vector_list.append(corpus[i].count(m))
			else:
				single_vector_list.append(0)

		top_level_vector_list.append(single_vector_list)
		single_vector_list=[]

	return top_level_vector_list

def clean(vocab):
	aandthe=['a','and','the','The']
	pronoun=['He','it','It','IT']
	frequent=['of']
	verbs=['was']
	merged=aandthe+pronoun+frequent+verbs
	vocab=set(vocab)
	merged=set(merged)
	vocab=list(vocab-merged)
	return vocab

def mapping2posneg()


if __name__ == "__main__":
	corpus = ['The food was great',
	'How great was the Veg Thali. great nuisance.',
	'The chef was bad in making the BhujiaShevpuri',
	]

	vocabulary = createvocab(corpus)
	print(vocabulary)
	vocab=[]
	vocab=list(vocabulary)
	vocab=clean(vocab)
	print(vocab)
	vectors=create_doc_vector(corpus,vocab)
	mapping2posneg



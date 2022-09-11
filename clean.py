import pandas as pd
Di = {'sent': [], 'para' : []}

idx = 0
fp = open('/home/zuhaib/CompetitiveWork/para-nmt-5m-processed/para-nmt-5m-processed.txt')
for line in fp:
    data = line.split('\t')
    idx += 1
    sent, par = data
    print("Index :" + str(idx))
    print("Sent: " + data[0])
    print("Para: " + data[1])
    id = input('Is this correct-Para :')
    if id == '1':
        Di['sent'].append(data[0])
        Di['para'].append(data[1])
    elif id == '2':
        break
    else:
        print("Total Paras till now:",len(Di['sent']))
        continue
    df = pd.DataFrame.from_dict(Di)
    df.to_csv('cleaned.tsv', index = False, sep = '\t')
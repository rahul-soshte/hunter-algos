import quandl
import pandas as pd
import pickle
import matplotlib.pyplot as plt
from matplotlib import style
style.use('fivethirtyeight')

# Not necessary, I just do this so I do not show my API key.
api_key = '7a1HAtuu-x75t_peV8h6'

# df = quandl.get("FMAC/HPI_TX", authtoken=api_key)
def mortgage_30y():
    df = quandl.get("FMAC/MORTG", trim_start="1975-01-01", authtoken=api_key)
    df["Value"] = (df["Value"]-df["Value"][0]) / df["Value"][0] * 100.0
    print(df.head())
    return df


# print(df.head())
def state_list():
	fiddy_states = pd.read_html('https://simple.wikipedia.org/wiki/List_of_U.S._states')
	return fiddy_states[0][1][2:]
# print(fiddy_states)
def grab_initial_state_data():
	states = state_list()
	main_df = pd.DataFrame()

	for abbv in states:
		query="FMAC/HPI_"+str(abbv)
		df= quandl.get(query, authtoken=api_key)	
		df = df.drop(df.columns[[1]], axis=1)
		df.rename(columns={'NSA Value': abbv}, inplace=True)
		df[abbv] = (df[abbv]-df[abbv][0]) / df[abbv][0] * 100.0

		if main_df.empty:
			main_df = df
		else:
			main_df = main_df.join(df)

		pickle_out = open('fiddy_states3.pickle','wb')
		pickle.dump(main_df, pickle_out)
		pickle_out.close()

# grab_initial_state_data()
# pickle_in = open('fiddy_states.pickle','rb')
# HPI_data = pickle.load(pickle_in)
# print(HPI_data)

# HPI_data.to_pickle('pickle.pickle')
# HPI_data = pd.read_pickle('fiddy_states3.pickle')
# # # # # print(HPI_data2)
# # # # HPI_data['TX2'] = HPI_data['TX'] * 2
# # # # print(HPI_data[['TX','TX2']].head())

# # HPI_data.plot()
# # plt.legend().remove()
# # plt.show()

def HPI_Benchmark():
	df = quandl.get("FMAC/HPI_USA", authtoken=api_key)
	df = df.drop(df.columns[[1]], axis=1)
	df.rename(columns={'NSA Value': "United States"}, inplace=True)
	df["United States"] = (df["United States"]-df["United States"][0]) / df["United States"][0] * 100.0
	return df

# # fig = plt.figure()
# ax1 = plt.subplot2grid((1,1), (0,0))

# # HPI_data = pd.read_pickle('fiddy_states3.pickle')
# # benchmark = HPI_Benchmark()
# # HPI_data.plot(ax=ax1)
# # benchmark.plot(color='k',ax=ax1, linewidth=10)

# # plt.legend().remove()
# # plt.show()

# HPI_data = pd.read_pickle('fiddy_states3.pickle')
# # HPI_State_Correlation = HPI_data.corr()
# # print(HPI_State_Correlation)

# TX1yr = HPI_data['TX'].resample('A')

# HPI_data['TX'].plot(ax=ax1)
# TX1yr.plot(color='k',ax=ax1)

# plt.legend()
# plt.show()

# df=mortgage_30y()
def sp500_data():
    df = quandl.get("YAHOO/INDEX_GSPC", trim_start="1975-01-01", authtoken=api_key)
    df["Adjusted Close"] = (df["Adjusted Close"]-df["Adjusted Close"][0]) / df["Adjusted Close"][0] * 100.0
    df=df.resample('M').mean()
    df.rename(columns={'Adjusted Close':'sp500'}, inplace=True)
    df = df['sp500']
    return df

def gdp_data():
    df = quandl.get("BCB/4385", trim_start="1975-01-01", authtoken=api_key)
    df["Value"] = (df["Value"]-df["Value"][0]) / df["Value"][0] * 100.0
    df=df.resample('M').mean()
    df.rename(columns={'Value':'GDP'}, inplace=True)
    df = df['GDP']
    return df

def us_unemployment():
    df = quandl.get("ECPI/JOB_G", trim_start="1975-01-01", authtoken=api_key)
    df["Unemployment Rate"] = (df["Unemployment Rate"]-df["Unemployment Rate"][0]) / df["Unemployment Rate"][0] * 100.0
    df=df.resample('1D').mean()
    df=df.resample('M').mean()
    return df
    
HPI_data = pd.read_pickle('fiddy_states3.pickle')
m30 = mortgage_30y()
sp500 = sp500_data()
gdp = gdp_data()
HPI_Bench = HPI_Benchmark()
unemployment = us_unemployment()
m30.columns=['M30']
HPI = HPI_Bench.join([m30,sp500,gdp,unemployment])
HPI.dropna(inplace=True)
print(HPI.corr())

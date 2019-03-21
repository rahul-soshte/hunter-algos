from tweepy import Stream
from tweepy import OAuthHandler
from tweepy.streaming import StreamListener
import time
import json
import sentiment_mod as s

#consumer key, consumer secret, access token, access secret.
ckey="ftCZKkpVGC2I8HKhUga3fizNp"
csecret="2WV1rGhBIGSaMkcySyyYW0ScknwvrTIqlBRY17MSZVngwhh4hM"
atoken="1381836288-s8YDu6pUWnaiDJTvl6VPCrv3dxqynBzzwGU65Tz"
asecret="DF2zPVM74H6N2dSMphcdPEv1SoHnOkRU4ARB4aIZWyvwU"

class listener(StreamListener):
	def on_data(self, data):
		all_data = json.loads(data)

		tweet = all_data["text"]
		sentiment_value, confidence = s.sentiment(tweet)
		print(tweet,
		 "Sentiment=",sentiment_value,
		 "Confidence",confidence)
		# time.sleep(5)

		if confidence*100 >= 80:
			output = open("twitter-out.txt","a")
			output.write(sentiment_value)
			output.write('\n')
			output.close()

		return True

	def on_error(self, status):
		print(status)

auth = OAuthHandler(ckey, csecret)
auth.set_access_token(atoken, asecret)

twitterStream = Stream(auth, listener())
twitterStream.filter(track=["happy"])
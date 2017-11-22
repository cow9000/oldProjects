echo "Insert phone number - "
read phonenumber arg1
echo "Message"
read -r message
while true
do
sleep 1
curl http://textbelt.com/text -d number=$phonenumber -d "message=$message"
done

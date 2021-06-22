ipsec whack --impair ignore-hard-expire
ipsec auto --up west
# 20 pings will get to almost rekey
ping -n -q -c 20 -I 192.0.1.254 192.0.2.254
# expect #2 IPsec original Child SA
ipsec trafficstatus
# next ping will go over and initiate a rekey
ping -n -q -c 1 -I 192.0.1.254 192.0.2.254
# expect #3 IPsec first rekeyed Child SA
sleep 5
ipsec trafficstatus
ping -n -q -c 28 -I 192.0.1.254 192.0.2.254
# expect #4 IPsec second rekeyed Child SA
sleep 5
ipsec trafficstatus
echo done
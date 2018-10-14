import pika

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

def callback(ch, method, properties, body):
    print(body)

if __name__ == '__main__':
    channel.queue_declare(queue='newConnection')
    channel.basic_consume(callback, queue="newConnection", no_ack=True)
    channel.start_consuming()
    print("loiasdof")
    

package smartExp;

import java.awt.EventQueue;
import java.util.Scanner;
import smartExp.SerialCommChannel;

public class View {
	private static final String serialPort = "/dev/tty.usbmodem14401"; // my arduino serial port
	
	public static void main(String[] args) throws Exception {
		var ex = new GUI();
	
	    EventQueue.invokeLater(() -> {
	        ex.setVisible(true);
	    });
	    
	    SerialCommChannel channel = new SerialCommChannel(serialPort, 9600);		
		System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");		
	
		while (true){
			String msg = channel.receiveMsg();
			String msg1 = "";
			String msg2 = "";
			String msg3 = "";
			if (msg.equals("START")) {
				System.out.println("Experiment Started");
				while(!msg1.equals("STOP") && !msg2.equals("STOP") && !msg3.equals("STOP")) {
					msg1 = channel.receiveMsg();
					msg2 = channel.receiveMsg();
					msg3 = channel.receiveMsg();
					if (!msg1.equals("STOP") && !msg2.equals("STOP") && !msg3.equals("STOP")) {
						ex.addValueToDataset1(msg1, msg2);
						ex.addValueToDataset2(msg1, msg3);
						System.out.println("msg1 " + msg1);
						System.out.println("msg2 " + msg2);
						System.out.println("msg3 " + msg3);
					}
				}
			}
			
			if (msg.equals("STOP")) {
				System.out.println("Experiment Stopped");
				Scanner keyboard = new Scanner(System.in);
				System.out.print("Write 'ok' for continue: ");
				String mychose = keyboard.nextLine();
				channel.sendMsg(mychose);
				keyboard.close();
			}
			
			if (msg.equals("IDLE")) {
				System.out.println("System ready for a new experiment");
			}
			
			if (msg.equals("SLEEP")) {
				System.out.println("System in sleep mode");
			}
		}
	}

}

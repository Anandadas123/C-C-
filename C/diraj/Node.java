package forms;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import java.awt.Color;

import javax.swing.border.LineBorder;
import javax.swing.plaf.SliderUI;
import javax.swing.table.DefaultTableModel;
import javax.swing.JLabel;

import java.awt.Font;

import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import config.IPAddr;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.lang.reflect.Array;
import java.net.Socket;
import java.net.UnknownHostException;
import java.sql.DatabaseMetaData;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

import javax.swing.JTextArea;
import javax.xml.crypto.dsig.spec.HMACParameterSpec;

import logic.AllNodeListener;
import logic.NodeListener;
import logic.PathFinder;
import logic.TempClientListener;

public class Node extends JFrame {

	public JPanel contentPane;
	public static JTextField txtNodeName;
	public static JTextField txtIPAddress;
	public static JTextField txtPortNo;
	public static JTextField txtTrArea;
	public static JTextField txtXloc;
	public static JTextField txtYloc;
	public static JTable tblOtherNodeInfo;
	public static JTable tblNeighborDetails;
	public static  JTable tblPathInfo;
	public static JButton btnConnectToServer;
	public static DefaultTableModel dtOtherNode;
	public static DefaultTableModel dtNeighbor;
	public static DefaultTableModel dtPath;
	public static JTextField txtSrcNode;
	public static JTextField txtPath;
	public static String ip="";
	public static int PortNo=4000;
	public static JLabel lblNodeInfo;
	private JTextField txtDestNode;
	public static JTextArea txtArRecvdMsg;
	public static JTextArea txtMsgAr;
	public static String path = "";
	public static long	x=0;
	public static int SameNodeCount;
	public static int min;
	public static JButton btnRouteRequest;
	public static JButton btnSend ;
	public static ArrayList alist= new ArrayList();
	
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Node frame = new Node();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Node() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(0, 0, 1025, 725);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(230, 230, 250));
		contentPane.setBorder(new LineBorder(new Color(0, 255, 0), 3));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		new TempClientListener();// Invokes TempClientListener
		
		JLabel lblNodeName = new JLabel("Node Name ::");
		lblNodeName.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblNodeName.setBounds(10, 25, 80, 14);
		contentPane.add(lblNodeName);
		
		JLabel lblIpAddress = new JLabel("IP Address ::");
		lblIpAddress.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblIpAddress.setBounds(10, 50, 73, 14);
		contentPane.add(lblIpAddress);
		
		JLabel lblPortNo = new JLabel("Port No ::");
		lblPortNo.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblPortNo.setBounds(10, 74, 60, 14);
		contentPane.add(lblPortNo);
		
		JLabel lblTransArea = new JLabel("Trans. Area ::");
		lblTransArea.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblTransArea.setBounds(10, 99, 80, 14);
		contentPane.add(lblTransArea);
		
		JLabel lblxLoc = new JLabel("'X' loc ::");
		lblxLoc.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblxLoc.setBounds(10, 124, 60, 14);
		contentPane.add(lblxLoc);
		
		JLabel lblyLoc = new JLabel("'Y' loc ::");
		lblyLoc.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblyLoc.setBounds(10, 149, 46, 14);
		contentPane.add(lblyLoc);
		
		txtNodeName = new JTextField();
		txtNodeName.setEditable(false);
		txtNodeName.setBounds(89, 22, 95, 20);
		contentPane.add(txtNodeName);
		txtNodeName.setColumns(10);
		
		txtIPAddress = new JTextField();
		txtIPAddress.setEditable(false);
		txtIPAddress.setBounds(89, 47, 131, 20);
		contentPane.add(txtIPAddress);
		txtIPAddress.setColumns(10);
		
		txtPortNo = new JTextField();
		txtPortNo.setEditable(false);
		txtPortNo.setBounds(89, 71, 86, 20);
		contentPane.add(txtPortNo);
		txtPortNo.setColumns(10);
		
		txtTrArea = new JTextField();
		txtTrArea.setEditable(false);
		txtTrArea.setBounds(89, 96, 86, 20);
		contentPane.add(txtTrArea);
		txtTrArea.setColumns(10);
		
		txtXloc = new JTextField();
		txtXloc.setEditable(false);
		txtXloc.setBounds(89, 121, 86, 20);
		contentPane.add(txtXloc);
		txtXloc.setColumns(10);
		
		txtYloc = new JTextField();
		txtYloc.setEditable(false);
		txtYloc.setBounds(89, 146, 86, 20);
		contentPane.add(txtYloc);
		txtYloc.setColumns(10);
		
		//Perform Connect to server task 
		btnConnectToServer = new JButton("Connect to NWInitiator");
		btnConnectToServer.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent e) 
			{
				try 
				{
					ip= IPAddr.get_IP();
					Socket skt= new Socket(IPAddr.get_IP(),5000);
					ObjectOutputStream oos= new ObjectOutputStream(skt.getOutputStream());
					oos.writeUTF("Connection");
					oos.writeUTF(ip);
					oos.writeInt(PortNo);
					oos.close();
					skt.close();
				}
				catch (UnknownHostException e1) 
				{
					e1.printStackTrace();
				} 
				catch (IOException e1)
				{
					e1.printStackTrace();
				}
				
				
				btnConnectToServer.setVisible(false);
			}
		});
		btnConnectToServer.setFont(new Font("Times New Roman", Font.BOLD, 12));
		btnConnectToServer.setBounds(23, 189, 197, 23);
		contentPane.add(btnConnectToServer);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(260, 49, 739, 147);
		contentPane.add(scrollPane);
		
		tblOtherNodeInfo = new JTable();
		scrollPane.setViewportView(tblOtherNodeInfo);
		
		dtOtherNode= new DefaultTableModel();
		dtOtherNode.addColumn("Node Name");
		dtOtherNode.addColumn("Port No");
		dtOtherNode.addColumn("IP Address");
		dtOtherNode.addColumn("Trans. Area");
		dtOtherNode.addColumn("'X'loc");
		dtOtherNode.addColumn("'Y'loc");
		tblOtherNodeInfo.setModel(dtOtherNode);
		
		
		JLabel lblOthernodeinfoTable = new JLabel("OtherNodeInfo Table");
		lblOthernodeinfoTable.setFont(new Font("Times New Roman", Font.BOLD, 11));
		lblOthernodeinfoTable.setBounds(579, 28, 118, 14);
		contentPane.add(lblOthernodeinfoTable);
		
		JLabel lblNeighbordetailsTable = new JLabel("NeighborDetails Table");
		lblNeighbordetailsTable.setFont(new Font("Times New Roman", Font.BOLD, 11));
		lblNeighbordetailsTable.setBounds(593, 198, 131, 14);
		contentPane.add(lblNeighbordetailsTable);
		
		JScrollPane scrollPane_1 = new JScrollPane();
		scrollPane_1.setBounds(260, 218, 739, 147);
		contentPane.add(scrollPane_1);
		
		tblNeighborDetails = new JTable();
		scrollPane_1.setViewportView(tblNeighborDetails);
		
		dtNeighbor= new DefaultTableModel();
		dtNeighbor.addColumn("Node Name");
		dtNeighbor.addColumn("Port No");
		dtNeighbor.addColumn("IP Address");
		dtNeighbor.addColumn("Trans. Area");
		dtNeighbor.addColumn("Co-Ordinates");
		dtNeighbor.addColumn("Distance");
		tblNeighborDetails.setModel(dtNeighbor);
		
		
		JScrollPane scrollPane_2 = new JScrollPane();
		scrollPane_2.setBounds(431, 391, 568, 165);
		contentPane.add(scrollPane_2);
		
		tblPathInfo = new JTable();
		scrollPane_2.setViewportView(tblPathInfo);
		
		dtPath= new DefaultTableModel();
		dtPath.addColumn("Dest. Node");
		dtPath.addColumn("Path");
		dtPath.addColumn("Total Distance");
		tblPathInfo.setModel(dtPath);
		
		JLabel lblPathTable = new JLabel("Route Table");
		lblPathTable.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblPathTable.setBounds(695, 377, 66, 14);
		contentPane.add(lblPathTable);
		
		JLabel lblSorceNode = new JLabel("Source Node ::");
		lblSorceNode.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblSorceNode.setBounds(23, 235, 86, 14);
		contentPane.add(lblSorceNode);
		
		JLabel lblPathFollowed = new JLabel("Path Followed::");
		lblPathFollowed.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblPathFollowed.setBounds(10, 260, 86, 14);
		contentPane.add(lblPathFollowed);
		
		txtSrcNode = new JTextField();
		txtSrcNode.setEditable(false);
		txtSrcNode.setBackground(new Color(240, 255, 240));
		txtSrcNode.setBounds(129, 232, 86, 20);
		contentPane.add(txtSrcNode);
		txtSrcNode.setColumns(10);
		
		txtPath = new JTextField();
		txtPath.setBackground(new Color(224, 255, 255));
		txtPath.setEditable(false);
		txtPath.setBounds(97, 257, 153, 20);
		contentPane.add(txtPath);
		txtPath.setColumns(10);
		
		lblNodeInfo = new JLabel("");
		lblNodeInfo.setBackground(new Color(255, 0, 0));
		lblNodeInfo.setFont(new Font("Times New Roman", Font.BOLD, 14));
		lblNodeInfo.setBounds(502, 11, 76, 14);
		contentPane.add(lblNodeInfo);
		
		//Perform Route Request task 
		btnRouteRequest = new JButton("Route Request");
		btnRouteRequest.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent arg0) 
			{
				dtPath.setRowCount(0);// Clear the table contents 
				
				String DestNode= txtDestNode.getText();
				
				int RowCount= dtNeighbor.getRowCount();
				
				if(RowCount > 0)
				{
					for(int i=0; i< RowCount;i++)
					{
						String n_Name	= dtNeighbor.getValueAt(i, 0).toString();
						int n_Port			= Integer.parseInt(dtNeighbor.getValueAt(i, 1).toString());
						System.out.println("%^%^%^-n_Port="+n_Port);
						String n_IP		= dtNeighbor.getValueAt(i, 2).toString();
						System.out.println("%^%^%^-n_IP="+n_IP);
						int n_Distance	= Integer.parseInt(dtNeighbor.getValueAt(i, 5).toString());
						String n_Path	= Node.txtNodeName.getText();
						
						try 
						{
							Socket skt= new Socket(n_IP,n_Port);
							ObjectOutputStream oos1= new ObjectOutputStream(skt.getOutputStream());
							oos1.writeUTF("Route_Request");
							oos1.writeUTF(Node.txtNodeName.getText());//Current source node
							oos1.writeUTF(DestNode);//Destination node
							oos1.writeUTF(n_Name);//Neighbor node
							oos1.writeInt(n_Port);// Port no of the neighbor node
							oos1.writeUTF(n_IP);// IP Address of the Neighbor node
							oos1.writeInt(n_Distance);// Distance of the neighbor node from Current source node
							oos1.writeUTF(n_Path);// Path consisting only source node now
							System.out.println("NN%*%*%*%*%*Current node="+n_Name);
							System.out.println("NN%%%%%%%%%Path="+n_Path);
							oos1.close();
							skt.close();
							//skt.close();//erhgfgfhfgffhfhf
						}
						catch (UnknownHostException e)
						{
							e.printStackTrace();
						}
						catch (IOException e) 
						{
							e.printStackTrace();
						} 
					}
				}
				else
				{
					//Show a message dialog when there will not be any neighbors.
					JOptionPane.showMessageDialog(null, "No Neighbors Available");
				}
			}
		});
		btnRouteRequest.setFont(new Font("Times New Roman", Font.BOLD, 12));
		btnRouteRequest.setBounds(674, 582, 118, 23);
		contentPane.add(btnRouteRequest);
		
		JLabel lblDestnNode = new JLabel("Enter the Destn. Node ::");
		lblDestnNode.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblDestnNode.setBounds(23, 348, 131, 14);
		contentPane.add(lblDestnNode);
		
		txtDestNode = new JTextField();
		txtDestNode.setBackground(new Color(224, 255, 255));
		txtDestNode.setBounds(164, 345, 86, 20);
		contentPane.add(txtDestNode);
		txtDestNode.setColumns(10);
		
		JScrollPane scrollPane_3 = new JScrollPane();
		scrollPane_3.setBounds(89, 412, 207, 61);
		contentPane.add(scrollPane_3);
		
		 txtMsgAr = new JTextArea();
		 scrollPane_3.setViewportView(txtMsgAr);
		
		JLabel lblSendMsg = new JLabel("Send Msg ::");
		lblSendMsg.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblSendMsg.setBounds(16, 433, 67, 14);
		contentPane.add(lblSendMsg);
		
		
		//Perform Message sending Operation
		btnSend = new JButton("Send");
		btnSend.addActionListener(new ActionListener() 
		{
			@SuppressWarnings("unchecked")
			public void actionPerformed(ActionEvent arg0) 
			{
				
				 int NeighrwCnt= dtNeighbor.getRowCount();
				 int rwCount = dtPath.getRowCount();
				 int countarr[]= new int[rwCount];
				 String[] nodearr	=	new String[NeighrwCnt];
				 String[] patharr	= 	new String[rwCount];
				 String[] splitarr	= 	new String[rwCount];
				
				 
				 if(rwCount > 0)
				 {
					for(int i=0; i < rwCount; i++)
					{
						patharr[i]= dtPath.getValueAt(i, 1).toString();
					}	
					
					for(int i=0; i < rwCount; i++)
					{
						System.out.println("%%%%Patharr["+i+"] ="+patharr[i]);
					}
					
					for(int i=0; i < rwCount; i++)
					{
						splitarr=patharr[i].split("\\:");// split path into its consisting nodes
						x 	= (int) splitarr.length; // assigning the length of Split array into x
						
						System.out.println("#####length of the array after splitting every node of the specific path="+x);
						countarr[i]= (int) x;
						
						for(int j=0; j < x; j++)//To print all node which is in path
						{
							System.out.println("%%%%%%%Nodes after splitting are:"+splitarr[j]);
						}
					}
					min	=	BubbleSort(countarr);// Calling bubble sort method
					System.out.println("%%%Minimum number of Nodes path contains::="+min);
				
				int key= min;
				SameNodeCount=0;
				String SameNodepath="";
				String[] splitter	= 	new String[min];
				
				alist.clear();
				for(int i=0; i < countarr.length; i++)
				{
					if( countarr[i] == key )
					{
						System.out.println("####   i ::"+i);
						SameNodepath= dtPath.getValueAt(i, 1).toString();
						SameNodeCount=	SameNodeCount+1;
						
						System.out.println("%!%!%!%SameNodePath at ["+i+"]="+SameNodepath);
						System.out.println("%*%*%SameNodeCount:"+SameNodeCount);
						
						splitter= SameNodepath.split("\\:");
						
						for(int z=0;z < min; z++)
						{
							System.out.println("%^%^%--splitter="+splitter[z]);
							alist.add(splitter[z]);
						}
						
						System.out.println("Size of the arraylist is ::"+alist.size());
					}
				}
				System.out.println("The contents of Arraylist ::");
				for(int z=0; z < alist.size(); z++)
				{
					System.out.println("%%%="+alist.get(z).toString());
				}

				for(int i=0; i < countarr.length; i++)																																																																		
				{
					if(min == 2)
					{
						if(SameNodeCount == 1)
						{
							path= SameNodepath;
							break;	
						}
						else
						{
							System.out.println("***!#^%Something is wrong%^#!***");
							break;
						}
					}	
					else if(min == 3)
					{
						if(SameNodeCount == 1)
						{
							path= SameNodepath;
							break;
						}
						else if(SameNodeCount > 1)
						{
							System.out.println("!!!!!!-Cursor is Inside the scope*****");
							System.out.println("!!!!!!-SameNodeCount="+SameNodeCount);
							int distance[]= new int[SameNodeCount];
							int d=0;
							while(d < SameNodeCount)  
							{
								System.out.println("!!!N!!!--d="+d);
								int y= d*min;
								System.out.println("!!!N!!!--y="+y);
								int z= d*min+1;
								System.out.println("!!!N!!!--z="+z);
								
								System.out.println("%%%-SRC-->INtr="+alist.get(y)+"-->"+alist.get(z));
								System.out.println("******");
								
								int dist=	 (AllNodeListener.hmap1.get(alist.get(y)+"-->"+alist.get(z)));
								System.out.println("#$#$%  Dist="+dist);
								System.out.println("***********");
								distance[d]= dist;
								d++;
							}
							System.out.println("********-- d="+d);
							int maxIndex=	maxDistanceIndex(distance);
							System.out.println("**********Index value in the 'distance' array at which distance is maximum is="+maxIndex);
							System.out.println("^^^^^^^^^^^Max Distance is="+distance[maxIndex]);
							path="" ;
							for(int c=0; c < min; c++)
							{
								System.out.println("^^^^^^^^^^-- c="+c);
								int index= (min*maxIndex)+c;
								String pth= alist.get(index)+"";
								path= path +":"+ pth;
								System.out.println("%%%%%%%%--path="+path);
							}
							path= path.substring(1, path.length());// To remove the ':'at index value 1
							System.out.println("^^^^^^^^^^^^^--Path="+path);
							System.out.println("&&&&&&&- Size of arraylist="+alist.size());
							break;
						}
					}
					else if(min > 3)
					{
						if(SameNodeCount == 1)
					 	{
							path= SameNodepath;
							break;
						}
						else if(SameNodeCount > 1)
						{
							System.out.println("Multiple path which consists of more than 3 nodes");
							System.out.println("!!!!!!-Cursor is Inside the scope*****");
							System.out.println("!!!!!!-SameNodeCount="+SameNodeCount);
							
							path= PathFinder.PathFind(alist);
							System.out.println("(((((((((((((((((--path="+path);
							break;
						}
					}
				}
			}
				 	int k = min-1;
				 	System.out.println("%%%% k ="+k);
				 	nodearr= path.split("\\:");
					String nextNode= nodearr[k];
					
					
					System.out.println("%%%nextNode::"+nextNode);
					String destNode = txtDestNode.getText();
					String msg			 = txtMsgAr.getText();
					String ip = "";
					int port   = 0;
					for(int i = 0; i < dtOtherNode.getRowCount(); i++){
						String nodeName = dtOtherNode.getValueAt(i, 0).toString();
						
						if(nodeName.equals(nextNode)){
							    ip = dtOtherNode.getValueAt(i, 2).toString();
							port = Integer.parseInt(dtOtherNode.getValueAt(i, 1).toString());
							break;
						}
					}
					
					try 
					{
						Socket st1 = new Socket(ip, port);
						ObjectOutputStream oos = new ObjectOutputStream(st1.getOutputStream());
						oos.writeUTF("Send-Msg");
						oos.writeUTF(destNode);//Destination Node
						oos.writeUTF(txtNodeName.getText());//Source Node
						oos.writeUTF(nextNode);//Next Node
						oos.writeUTF(msg);//Message to be sent
						oos.writeUTF(path);//PATH
						oos.writeInt(k);//Node Index
						oos.writeObject(nodearr);
						oos.close();
						st1.close();
						} 
					
					catch (UnknownHostException e)
					{
						e.printStackTrace();
					} 
					
					catch (IOException e) 
					{
						e.printStackTrace();
					}
				}
			
		});
		btnSend.setFont(new Font("Times New Roman", Font.BOLD, 14));
		btnSend.setBounds(674, 653, 89, 23);
		contentPane.add(btnSend);
		
		JScrollPane scrollPane_4 = new JScrollPane();
		scrollPane_4.setBounds(90, 534, 206, 70);
		contentPane.add(scrollPane_4);
		
		txtArRecvdMsg = new JTextArea();
		scrollPane_4.setViewportView(txtArRecvdMsg);
		txtArRecvdMsg.setEditable(false);
		
		JLabel lblRecievedMsg = new JLabel("Recieved Msg ::");
		lblRecievedMsg.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblRecievedMsg.setBounds(4, 559, 86, 14);
		contentPane.add(lblRecievedMsg);
		
		JButton btnHashDetailsSend = new JButton("Send Request for  Neighbor  Details ");
		btnHashDetailsSend.setForeground(new Color(0, 0, 0));
		btnHashDetailsSend.setBackground(new Color(173, 255, 47));
		btnHashDetailsSend.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent arg0) 
			{
				String SrcNode=	Node.txtNodeName.getText();
				int Srcport=			Integer.parseInt(Node.txtPortNo.getText());
				String SrcIP=		Node.txtIPAddress.getText() ;
				
				try 
				{
					Socket soc=	new Socket(IPAddr.get_IP(), 5000);
					ObjectOutputStream ost= new ObjectOutputStream(soc.getOutputStream());
					ost.writeUTF("Send Hashmap");
					ost.writeUTF(SrcIP);
					ost.writeInt(Srcport);
					ost.close();
					soc.close();
				} 
				catch (UnknownHostException e) 
				{
					e.printStackTrace();
				} catch (IOException e) 
				{
					e.printStackTrace();
				}
			}
		});
		btnHashDetailsSend.setFont(new Font("Times New Roman", Font.BOLD, 12));
		btnHashDetailsSend.setBounds(674, 616, 290, 23);
		contentPane.add(btnHashDetailsSend);
		
		JLabel label = new JLabel("1.");
		label.setForeground(new Color(0, 0, 255));
		label.setFont(new Font("Times New Roman", Font.BOLD, 14));
		label.setBounds(652, 591, 17, 14);
		contentPane.add(label);
		
		JLabel label_1 = new JLabel("2.");
		label_1.setForeground(new Color(0, 0, 255));
		label_1.setFont(new Font("Times New Roman", Font.BOLD, 14));
		label_1.setBounds(652, 619, 17, 14);
		contentPane.add(label_1);
		
		JLabel label_2 = new JLabel("3.");
		label_2.setForeground(new Color(0, 0, 255));
		label_2.setBackground(Color.WHITE);
		label_2.setFont(new Font("Times New Roman", Font.BOLD, 14));
		label_2.setBounds(652, 657, 17, 14);
		contentPane.add(label_2);
	}

	public int BubbleSort(int[] countarr)
	  {
	    int i, j, swap;
	    int n= countarr.length;
	    int minimum=0;
	   
	    int[] array= new int[n];
	   
	    array=Arrays.copyOf(countarr, n);
	    System.out.println("The contents of the array are::");
	    for (i = 0; i < n  ; i++) 
	    {
	    	System.out.println("*"+array[i]+"*");
	    }
	   
	    for (i = 0; i < ( n - 1 ); i++) 
		{
	      for (j = 0; j < (n - i - 1); j++) 
		  {
	        if (array[j] > array[j+1]) /* For desiending order use < */
	        {
	        		swap       	= array[j];
	        		array[j]		= array[j+1];
	        		array[j+1] 	= swap;
	        }
	      }
	    }
	    System.out.println("Sorted list of numbers");
	    for (i = 0; i < n; i++) 
	    {
	    	System.out.println(array[i]);
	    }
	      minimum= array[0];
	      return minimum;
	  }
	
	public int maxDistanceIndex(int distance[])
	{
		int   max = distance[0];
		int num=0;
		for(int i = 1; i<distance.length; i++)
		{
			if(distance[i] > max)
			{
				num=i;
				max= distance[i];
			}
		}
		System.out.println(" num Index="+num);
		System.out.println("/****/MaxDistance="+max);

		return num;
	}
}

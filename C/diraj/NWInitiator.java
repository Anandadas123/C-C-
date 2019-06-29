package forms;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.Color;

import javax.swing.border.LineBorder;
import javax.swing.table.DefaultTableModel;
import javax.swing.JLabel;

import java.awt.Font;

import javax.swing.JButton;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import logic.NodeListener;

public class NWInitiator extends JFrame {

	private JPanel contentPane;
	private JScrollPane scrollPane;
	private JTable tblSever;
	private JLabel lblAllnodeinfoTable;
	public static DefaultTableModel dtServer;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					NWInitiator frame = new NWInitiator();
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
	public NWInitiator() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(0, 0, 850, 600);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(30, 144, 255));
		contentPane.setBorder(new LineBorder(new Color(0, 255, 0), 2));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		new NetworkGraph().setVisible(true);
		
		new NodeListener();
		
		JLabel lblServer = new JLabel("NWInitiator");
		lblServer.setForeground(new Color(0, 255, 255));
		lblServer.setFont(new Font("Times New Roman", Font.BOLD, 15));
		lblServer.setBounds(382, 11, 93, 14);
		contentPane.add(lblServer);
		
		scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 147, 814, 308);
		contentPane.add(scrollPane);
		
		tblSever = new JTable();
		scrollPane.setViewportView(tblSever);
		
		dtServer= new DefaultTableModel();
		dtServer.addColumn("Node Name");
		dtServer.addColumn("Port No");
		dtServer.addColumn("IP Address");
		dtServer.addColumn("Trans. Area");
		dtServer.addColumn("'X'loc");
		dtServer.addColumn("'Y'loc");
		tblSever.setModel(dtServer);
		
		lblAllnodeinfoTable = new JLabel("AllNodeInfo Table");
		lblAllnodeinfoTable.setFont(new Font("Times New Roman", Font.BOLD, 12));
		lblAllnodeinfoTable.setBounds(385, 122, 113, 14);
		contentPane.add(lblAllnodeinfoTable);
	}
}

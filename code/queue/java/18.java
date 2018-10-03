package gqq.dp.bridge;

import gqq.dp.common.*;

public class Queue extends Container {

	public Queue(ContainerImp imp) {
		super(imp);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void count() {
		// TODO Auto-generated method stub
		Out.print("���У����Ԫ�ؼ���");
	}

	@Override
	public void add() {
		// TODO Auto-generated method stub
		super.add();
		Out.print("��ӵ���β");
	}

	@Override
	public void fetch() {
		// TODO Auto-generated method stub
		super.fetch();
		Out.print("�Ӷ��׿�ʼȡ");
	}

}

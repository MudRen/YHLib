inherit ROOM;

void create()
{
  	set ("short", "����·��");
  	set ("long", @LONG
��·���˷�Ϊ��·��һ��·�򱱾��ǿ���ǣ�����������
���֡�����������С���������������·ͨ��Ұ���֡�
LONG);

  	set("outdoors", "kaifeng");
  	set("exits", ([
  		"southwest" : __DIR__"dadao2",
  		"southeast" : __DIR__"shulin",
  		"north" : __DIR__"dadao",
	]));

  	setup();
  	replace_program(ROOM);
}

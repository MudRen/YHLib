inherit ROOM;

void create()
{
  	set ("short", "����");
  	set ("long", @LONG
һ��������ͷ�����̵�������б�����������ɫ�Ĺ��͸
����Ҷ�ڵ����������������ˢˢ����������Զȥ��������
���м䱻�˿�����һƬ�յأ�������һ��Сé�ݡ�
LONG);

  	set("outdoors", "kaifeng");
  	set("exits", ([
  		"enter" : __DIR__"zhulin1",
  		"west":__DIR__"fanta",
	]));
  	setup();
  	replace_program(ROOM);
}

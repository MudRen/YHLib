inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
Ͽ������ʯ�ڶ�Ȼ�����������õ����ɣ�̧ͷ���죬ֻ��
��ɫ��������������Ǳ�ں�������һ�㡣Ͽ����ʯȫ�����ɫ
�Ե��ڹⷢ������·������ȥ�������쳣��Ͽ�ڳ��л�ѩ����
����ӳ��εΪ��ۡ�
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
  		"west" : __DIR__"caoyuan6",
  		"east" : __DIR__"xingxing1",
	]));
	setup();
	replace_program(ROOM);
}

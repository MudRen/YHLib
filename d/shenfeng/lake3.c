inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
Ϫˮת���ƹ�һ��ߵأ���Ȼ��ǰһƬ���٣�ˮ����䲻
����ƥ������������������齦�񣬶ٳ���ۡ���������Ĵ�
Į֮��ͻȻ�������������������ˬ�����������뿴���ٲ�
֮�ϸ�����ô��ɫ��
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
  		"west" : __DIR__"lake4",
  		"south" : __DIR__"lake2",
	]));

	setup();
	replace_program(ROOM);
}

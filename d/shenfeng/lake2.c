inherit ROOM;

void create()
{
	set("short", "СϪ");
	set("long", @LONG
������ҫ֮�У����������л���Ʈ����Ϫˮ���㣬������
���л�֮�ʣ���Ϫˮ��������ȥ������Ϫ������ɳĮ�еĺ�
��������ˮ�󣬵�����ˮ���𽥱�ɳĮ���ɣ�������ʧ����
��Ϫ����ľҲ�������ˡ�
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
  		"north" : __DIR__"lake3",
  		"south" : __DIR__"lake1",
	]));

	setup();
	replace_program(ROOM);
}

inherit ROOM;

void create()
{
	set("short", "��Į���");
	set("long", @LONG
���Ƶ����ǻ�Ȼ���ʣ����������һ���޼ʵ�ɳĮ�����
�ں����������ɳ�ڷ��裬��ɳ������ɳ������������ϣ���
���ǲ��ŭͶ�µı�����ڤڤ�з·�������а����������κ�
����ʱ���п���ͻȻ��Ұ��������ɳ���ϡ�
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
		"west" : __DIR__"shamo3",
		"east" : __DIR__"shamo1",
	]));
	setup();
	replace_program(ROOM);
}

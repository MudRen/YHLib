inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
���Ƕ����ϵ�һ���Ӳݴ�������С·��������ƽʱûʲ
ô�˼���·�߿��Ų�֪��Ұ��������������Ȼ�ߴ�ͦ�Ρ�����
͸�����յ��������ǰ߲߰�����Ӱ�ӡ�
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"xiaolu2",
		"westup"    : __DIR__"zulin1",
	]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}


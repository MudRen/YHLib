inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
���Ƕ����ϵ�һ���Ӳݴ�������С·��������ƽʱûʲ
ô�˼���·�߿��Ų�֪����Ұ��������������Ȼ�ߴ�ͦ�Ρ���
��͸�����յ��������ǰ߲߰�����Ӱ�ӡ�
LONG);
	set("exits", ([
		"west" : __DIR__"biangate",
		"east" : __DIR__"xiaolu2",
	]));
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}


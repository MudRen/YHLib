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
                 "southeast" : __DIR__"shanlu1",
		"westup"    : __DIR__"xiaolu3",
	]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}


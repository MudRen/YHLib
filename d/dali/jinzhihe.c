inherit ROOM;

void create()
{
	set("short","��֭����");
	set("long",@LONG
����λ����֭���ϣ�ԭ������һ���ز��£������Ժ��ϡ�Ψ��һ��
ʯ�̾���(jingzhuang)�������С��˴�Ϊ��׶״���߲�ʯ�񡣸�Լ����ߣ�
����Ϊ�˽��ε���ʯ�����Ͽ��������������֮���н�ʯ�����Ǳ���֮��
�ܣ������ϲ�֮��ʯ��
LONG);
	set("item_desc", ([
                "jingzhuang" : "���Ǹ�ϡ����������ȥ����Ҳ������\n",
	]));
	set("exits", ([
                "east"  : __DIR__"yanchi1",
                "west"  : __DIR__"xiaojing",
                "enter" : __DIR__"jingzhuang1",
	]));
	set("objects", ([
                __DIR__"npc/seng": 2,
                "/clone/npc/walker" : 1,
	]));
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}


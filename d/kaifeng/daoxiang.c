inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����������������ʷ�ˡ����ⶰ¥����ںڵ��������
�ܿ����������������ʳ�ͻ���ͦ�ࡣ�����������ˡ�¥�ϵ�
Ȼ��������������Ҫ��һ����ݵ�λ���˲����ϡ�
LONG
        );
        set("exits", ([
		"up" : __DIR__"daoxiang2",
		"west" : __DIR__"road2",
		"east" : __DIR__"majiu",
	]));
        set("no_clean_up", 0);
        set("objects", ([
	        "/d/city/npc/xiaoer2" : 1,
	]));

        setup();
        replace_program(ROOM);
}

inherit ROOM;

void create()
{
        set("short", "��ױ��");
        set("long", @LONG
������Ա�Ļ�ױ�䣬������Ա�����ž��ӻ�ױ��Ҳûע��
�������ǽ��һ����źܶ��·������ϵĹ����Ϸ��˺ü�����
�ߣ��Ǹ���߿���ȥ�ܾ��ɣ���������������Լ����档
LONG);

        set("exits", ([
                "east" : __DIR__"xiyuan1",
                        
	]));
        set("objects", ([
                "/d/beijing/npc/xizi1" : 2,
                "/d/beijing/npc/xizi2" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

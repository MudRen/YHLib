inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��ɳĮ�ľ�ͷ������һ�����ޡ�������Ͻ��ѵ�һ���Ĳ�
ԭ����ԭ�ϵ�ҹ����ܸߡ����������Ǻ�������ݺ�С��ɢ
�������㡣����ԼԼ�����Ʈ��������ĸ����������ס�Ź�
������, �Է�����ȺΪ������ľ������һ�ۿ���������̨����
��ľ��ר���ڿʵ����˺�ˮ��������һ��ϵء�
LONG);
        set("outdoors", "gaochang");
        set("exits", ([
                "west" : __DIR__"huijiang3",
                "north" : __DIR__"huijiang7",
                "east" : __DIR__"lake4",
        ]));
        set("objects", ([
            	__DIR__"npc/su" : 1,
                "/clone/quarry/yang" : 2,
        ]));
        set("quarrys", ([
                "yang"  : 50000,
                "lang"  : 30000,
                "ying"  : 10000,
        ]));
        setup();
        replace_program(ROOM);
}

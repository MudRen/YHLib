inherit ROOM;

void create()
{
        set("short", "��³��");
        set("long", @LONG
�˳����������������θ����������³�����ݡ��²�����
���Ĵ󡣸�����ɽ�ش��֣����������Ϊ�����ӹ��ڵ͵�Ҳ��
��Ƥ���ʺϷ���ţ�򡣶���ƽԭ�����д���
LONG);
        set("objects", ([
                "/clone/quarry/yang2"  : 2,
                __DIR__"npc/muyangren" : 1,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "northup" : __DIR__"shanlin",
                "south"   : __DIR__"zhenxiong",
                "east"    : __DIR__"minadian",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

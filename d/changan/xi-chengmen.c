inherit ROOM;

void create ()
{
        set ("short", "����������");
        set ("long", @LONG
�����ǵ������š�����Ļ��ǺӼ������������ҳǸ�ǽ����һ��
���أ����Ī��֮�ƣ����ڻ�פ������Ӫʿ����Զ����Ӫ���࣬�����
�����ľ�����֮�ƣ�������¥��ֻ����¥�ߴ������ڱ����������ţ�ʿ
�����   
LONG);
        set("exits", ([
                "west" : "/d/xingxiu/xxroad1",
                "east" : __DIR__"xian-daokou",
        ]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/guanbing" :2,
                "/clone/npc/walker" : 1,
        ]));

        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}

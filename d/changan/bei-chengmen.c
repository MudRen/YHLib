inherit ROOM;

void create ()
{
        set ("short", "����������");
        set ("long", @LONG
�����ǵı����š�����Ļ��ǺӼ������������ҳǸ�ǽ����һ��
���أ����Ī��֮�ƣ����ڻ�פ������Ӫʿ����Զ����Ӫ���࣬�����
�����ľ�����֮�ƣ�������¥��ֻ����¥�ߴ������ڱ����������ţ�ʿ
�����   
LONG);
        set("exits", ([
                "north" : __DIR__"tulu1",
                "south" : __DIR__"beian-daokou",
        ]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/guanbing" : 2,
                "/clone/npc/walker" : 1,
        ]));

        set("outdoors", 1);
        setup();
        replace_program(ROOM);
}

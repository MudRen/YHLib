inherit ROOM;

void create()
{
        set("short", "���ǹ�");
        set("long", @LONG
�������Ǵ�������һ��Ƨ�����ڣ����¾����˼���ǰǰ��
�ᣬ���СС���������������׵�ҫ�۵�ѩ�������š�����ɫ
��ɽҰ��ѩ������ҫ�ź�ɫ����ɫ�Ĺ��������ͷף��Թ���
����¥�ɸ�������ǰ���֡�����һ��С����֪ͨ���δ���
LONG);
        set("exits", ([
                "westup" : __DIR__"sroad8",
                "eastup" : __DIR__"sroad9",
        ]));
        set("objects", ([
                __DIR__"npc/zhuoma" :1,
                __DIR__"npc/yangzong" :1,
                CLASS_D("xuedao") + "/shanyong" : 1,
        ]));
        set("outdoors", "xuedao");
        setup();
        replace_program(ROOM);
}


inherit ROOM;

void create()
{
        set("short", "�ⷿ");
        set("long", @LONG
���������䳡�Աߵ�С�ⷿ�������ܲ�ͨ�磬ֻ��һ˿��
�ߴ�����С����Ͷ�������������Щ���õ�����������ѩɽ��
���ճ�������Ҫ�õ��ı�����
LONG);
        set("exits", ([
                "east" : __DIR__"chang",
        ]));
        set("objects", ([
                "/clone/weapon/zhujian" : random(2),
                "/clone/weapon/gangdao" : random(2),
                __DIR__"obj/mugun" : random(2),
                __DIR__"obj/falun" : random(2),
        ]));
        setup();
}

// /guanwai/songlin2.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @long
�������ֺó������˰��ʱ����ʼ���꣬һ�����֣�����һ��ɽ����¡�ɽ
�������ߣ�������һ���ʹܰ�������Ⱥɽ֮�У������쳣��Ī˵���ˣ���
��Գ��Ҳ�ǲ�����ȥ��        
long );
        set("exits", ([
                "east"    : __DIR__"songlin6",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}

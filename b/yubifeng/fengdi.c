// /guanwai/fengdi.c

inherit ROOM;

void create()
{
        set("short", "��ʷ���");
        set("long", @long
�������ֺó������˰��ʱ����ʼ���꣬һ�����֣�����һ��ɽ����¡�ɽ
�������ߣ�������һ���ʹܰ�������Ⱥɽ֮�У������쳣������ǧ�𣬷�
ͬС�ɡ�Ī˵���ˣ�����Գ��Ҳ�ǲ�����ȥ��        
long );
        set("exits", ([
                "north"    : __DIR__"songlin5",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������Сɽ���£����������һ�������������ǽ�ݶ�
��ʽ�����ڵغ��˵�ש�ݣ�ֻ����Ϊ��ª��ֻ��С��֮��ϵ��
ƥ��ͷ�������ȳ��ࡣ�����ĵ�����С�����棬����̽ͷ��
������������������֪������һ����ͬʱ̽��������
LONG);
        set("outdoors", "gaochang");
        set("exits", ([
            	"north" : __DIR__"huijiang3",
        ]));
        set("objects", ([
                __DIR__"npc/ji"  : 1,
        ]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

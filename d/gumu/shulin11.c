
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬
ֻ���ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩
��Ũ�ܵ�֦ͷ��Ͷ����¡�ż��Զ�������޺�����������һ��
���ܸС��������ϸ���һ��С����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "south"     : __DIR__"shulin10",
                "northdown" : __DIR__"shulin12",
        ]));
        setup();
        replace_program(ROOM);
}

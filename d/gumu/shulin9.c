

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬
ֻ���ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩
��Ũ�ܵ�֦ͷ��Ͷ����¡�ż��Զ�������޺�����������һ��
���ܸС����������ϸ���һ��С����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "north"      : __DIR__"baoziyan",
                "southdown"  : __DIR__"shanlu9",
        ]));

        setup();
        replace_program(ROOM);
}

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ��������
ֻ���ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩
��Ũ�ܵ�֦ͷ��Ͷ����¡�ż��Զ�������޺�����������һ��
���ܸС�����������������һ��С����
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "northwest" : __DIR__"shenheyuan",
                "east"      : __DIR__"baoziyan",
        ]));
        set("objects", ([
                "/clone/quarry/lu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

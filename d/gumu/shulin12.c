inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ��������
ֻ���ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩
��Ũ�ܵ�֦ͷ��Ͷ����¡�ż��Զ�������޺�����������һ��
���ܸС��������ϸ���һ��С����
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "southup"   : __DIR__"shulin11",
                "northdown" : __DIR__"shandao3",
        ]));
        set("objects", ([
                "/clone/quarry/hou" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

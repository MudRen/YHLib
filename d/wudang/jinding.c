inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
��е���������Ϯ����ԭ�����ѵ����䵱ɽ������������
�ľ�����ǰ��Ľ����ͭ���ɣ����Իƽ�ÿ�������ٿգ���
�������������������𶥡�������߸߶�����Ⱥ���ϣ�����
������ɽ����������壬�б�һɽ����¯����¯�壬��ɽǧ��
�����·���
LONG);
        set("exits", ([
                "northdown": __DIR__"santiangate",
                "south"    : __DIR__"zijincheng",
                "west"     : __DIR__"shierliantai",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

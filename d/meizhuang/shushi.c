inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ͺ���̵����ң�������һ���󰸣����Ϸ���һ����Ͳ����
Ͳ�в��ż��ܴ�С��ͬ��ë�ʣ�ë�ʵ�����Ҳ������ͬ�����Ǻ�����
����������ף������룬����һ֧���Ϻ��Ѽ�����̡���ʣ�����ƽ��
��һ���ĳ����ô�С����ֽ��һ�����⣬һ����ī��һ�԰�����ֽ��
һ����ɽ�ʼܣ����Գ����˶��鷨�İ��á�ǽ�Ϲ�����������д��һ
�������������ã������� 
LONG
        );
        set("exits", ([
                "east" : __DIR__"zoulang1",
        ]));

        set("objects", ([
                CLASS_D("meizhuang") + "/tubi" : 1,
                __DIR__"obj/maobi" : 2,
                __DIR__"obj/panguanbi" : 1,
        ]));

        set("outdoors", "meizhuang");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

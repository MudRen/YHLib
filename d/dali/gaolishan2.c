inherit ROOM;

void create()
{
        set("short", "����ɽ����");
        set("long", @LONG
����ɽ�ϵ����ն�����������������������̡��ش�
��ɽ�ļ��Ժ����ܻ�������ʱ����û��ֻ���¸ҵ����˲Ÿ���
��������������ɽ������ˮ�ȵء�
LONG);
        set("objects", ([
                "/clone/quarry/laohu" : 1,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "east"  : __DIR__"gaolishan1",
        ]));
        setup();
        replace_program(ROOM);
}

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ǰ���ɽׯ�Ĵ������ڲ����輫������������һ�ź�ɫ
̴ľ����������·��ž����Ļ�ƿ��һЩ���Ĵ������ıڹ�
�����ҵ��ֻ����ǳ�֮��Ŀ��
LONG);
        set("valid_startroom", 1);
        set("exits", ([
                "north" : __DIR__"liangong",
                "southdown" : __DIR__"yuanzi",
        ]));
 
        set("objects",([
                CLASS_D("ouyang") + "/ouyangfeng" : 1,
                __DIR__"npc/yahuan" : 2,
        ]));

        setup();

        "/clone/board/baituo_b"->foo();
        replace_program(ROOM);
}

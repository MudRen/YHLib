inherit ROOM;

string* npcs = ({
        "/clone/worm/changtuizhu",
        "/clone/worm/huabanzhu",
        "/clone/worm/baizuwugong",
        "/clone/worm/qianjiewugong",
        "/clone/worm/datouwugong",
        "/clone/worm/changaoxie",
        "/clone/worm/huibeixie",
});

void create()
{
        set("short", "�ٶ���");
        set("long", @LONG
������һ����Ȼ�γɵ�ʯ�������������󡣶��������������
��ʯ����ʱ���������δ��ˮ�������ڶ��У�����������ʪ�����Ժ�
Ȼ����һ�����С���������
LONG );
        set("exits", ([
                "east" : __DIR__"baidu2",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
        ]));

        setup();
        replace_program(ROOM);
}

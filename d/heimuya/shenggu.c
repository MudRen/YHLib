inherit ROOM;
 
void create()
{
        set("short", "ʥ����");
        set("long", @LONG
�����Ǻ�ľ�µġ�ʥ�á���ӯӯ���ڵ�ʥ���á��������
���ޣ�ɷ��Ư������������һλ����Ů�ӣ�����С�䣬���޲�
�ɷ����Ц��ŭ������
LONG );
        set("exits", ([
            	"east" : __DIR__"chitang",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/ying" : 1,
        ]));       
        setup();
        replace_program(ROOM);
}
